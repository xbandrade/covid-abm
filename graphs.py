import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import warnings
import os


def plot():
    vac = 85  # percentage vaccinated
    v = 8  # vaccine
    s = 1  # state
    irange = range(0, 101, 5)
    state = ['Infectious', 'Hospitalized', 'Vaccinated']
    df = [pd.read_csv(f'newsim1/v{str(v)}-{vac}/i{str(iso)}/epiPrev.csv') for iso in irange]
    t = df[0]['Time'].to_numpy()
    inf = [d[state[s]].to_numpy() for d in df]
    labels = list(map(str, irange))
    fig, ax = plt.subplots(1, 1, figsize=(8.8, 5.7))
    ax.grid()
    ax.set_xlim(0, 400)
    # if s == 0:
    #     ax.set_ylim(0, .28)
    #     plt.yticks(np.arange(0, .28, .04))
    for i, x in enumerate(inf):
        ax.plot(t, x, label=labels[i])
    ax.legend(bbox_to_anchor=(1.15, 1), loc='upper right')
    plt.tight_layout()
    plt.show()


def heatmap(v, p, sim):
    s = 1 if sim == 3 else 0
    fig, ax = plt.subplots(1, 1, figsize=(8.8, 5.7))
    vac_d = {0: 'No Vaccination', 1: 'AstraZeneca', 2: 'CoronaVac', 4: 'Janssen', 6: 'Pfizer', 8: 'Vaccines Used in Brazil'}
    state = ['Infectious', 'Hospitalized', 'Vaccinated']
    yrange = range(100, -1, -5)
    if sim == 1:
        df = [pd.read_csv(f'newsim1/v{v}-{p}/i{iso}/epiPrev.csv') for iso in yrange]
    elif sim == 2:
        df = [pd.read_csv(f'newsim2/i{p}/v{v}/v{vac}/epiPrev.csv') for vac in yrange]
    else:
        df = [pd.read_csv(f'newsim3/v{v}/{p}/i{iso}/epiPrev.csv') for iso in yrange]
    inf = [d[state[s]].to_numpy() for d in df]
    titles = [f'{i}' for i in range(100, -1, -5)]
    inf = pd.DataFrame(inf, titles)
    sns.heatmap(inf, cmap='flare_r')
    ax.set_xticks(np.arange(0, 401, 50))
    ax.set_xticklabels((c for c in np.arange(0, 401, 50)), rotation=0)
    ax.set_xlabel('Time(days)')
    cbar = ax.collections[0].colorbar
    cticks = [float(t.get_text().replace('−','-')) for t in cbar.ax.get_yticklabels()]
    if sim == 1:
        cbar.ax.set_yticklabels(map(lambda s: f'{round(s*100, 1)}%', cticks))
        plt.title(f'$P_{{vac}}={p}\%$ - {vac_d[v]}')
        plt.ylabel('$P_{iso} (\%)$')
        plt.tight_layout()
        plt.savefig(f'heatmaps/sim1/v{v}_v{p}.png')
    elif sim == 2:
        cbar.ax.set_yticklabels(map(lambda s: f'{round(s*100, 1)}%', cticks))
        plt.title(f'$P_{{iso}}={p}\%$ - {vac_d[v]}')
        plt.ylabel('$P_{vac} (\%)$')
        plt.tight_layout()
        plt.savefig(f'heatmaps/sim2/v{v}_i{p}.png')
    else:  # 0.1255808364
        if v == 6 and p == 100:
            cbar.ax.set_yticklabels(map(lambda s: f'{round(100 * s * 1e-5 / 0.001255808364, 1)}%', cticks))
        else:
            cbar.ax.set_yticklabels(map(lambda s: f'{round(100 * s / 0.001255808364, 1)}%', cticks))
        plt.title(f'$P_{{vac}}={p}\%$ - {vac_d[v]}')
        plt.ylabel('$P_{iso} (\%)$')
        plt.tight_layout()
        plt.savefig(f'heatmaps/sim3/Hv{v}_v{p}.png')
    # plt.show()


def main():
    # plot()  # normal_plot
    vac = 85
    params = {'mathtext.default': 'regular' }     
    plt.rcParams["font.family"] = "courier new"     
    plt.rcParams.update(params)
    # Sim 1
    for v in (0, 1, 2, 4, 6, 8):
        print(f'vac {v} - v{vac}%... ', end='')
        heatmap(v, vac, 1)
    print('\nSim 1 done!')
    # Sim 2
    for iso in (0, 50):
        for v in (0, 1, 2, 4, 6, 8):
            print(f'vac {v} - i{iso}%... ', end='')
            heatmap(v, iso, 2)
        print()
    print('Sim 2 done!')
    # Sim 3
    for v in (0, 1, 2, 4, 6, 8):
        for vac in (0, 25, 50, 75, 100):
            if (vac == 0 and v > 0) or (v == 0 and vac > 0):
                continue
            print(f'vac {v} - v{vac}%... ', end='')
            heatmap(v, vac, 3)
        print()
    print('Sim 3 done!')
    

if __name__ == '__main__':
    paths = ['heatmaps/sim1', 'heatmaps/sim2', 'heatmaps/sim3']
    warnings.filterwarnings('ignore')
    try:
        for p in paths:
            os.makedirs(p, exist_ok=True)
    except OSError as e:
        print('Could not create directories. Exiting...')
    else:
        main()
