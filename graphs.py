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
    for i, x in enumerate(inf):
        ax.plot(t, x, label=labels[i])
    ax.legend(bbox_to_anchor=(1.15, 1), loc='upper right')
    plt.tight_layout()
    plt.show()


def interpolate(dt, yrange):
    new_dt = []
    counter = 0
    diff = [0]
    for i in range(100, -1, -1):
        if i in yrange:
            new_dt.append(dt[counter])
            counter += 1
        else:
            new_dt.append([])
    for i in range(100, -1, -1):
        if i % 5 == 0 and i > 0:
            diff = [(new_dt[i - 5][k] - new_dt[i][k])/5 for k in range(401)]
        else:
            new_dt[i] = [new_dt[i + 1][k] + diff[k] for k in range(401)]
    return new_dt


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
    inf = interpolate([d[state[s]].to_numpy() for d in df], yrange)
    max_val = max(np.asmatrix(d).max() for d in inf)
    titles = [f'{i}' for i in range(100, -1, -1)]
    inf = pd.DataFrame(inf, titles)
    sns.heatmap(inf, cmap='flare_r')
    ax.set_xticks(np.arange(0, 401, 50))
    ax.set_yticks(np.arange(100, -1, -10))
    ax.set_xticklabels((c for c in np.arange(0, 401, 50)), rotation=0)
    ax.set_yticklabels((c for c in np.arange(0, 101, 10)))
    ax.set_xlabel('Time(days)', fontsize=16)
    cbar = ax.collections[-1].colorbar  # type: ignore
    cbar.set_ticks(np.linspace(0, max_val, 10))
    cticks = [float(t.get_text().replace('−','-')) for t in cbar.ax.get_yticklabels()]
    if sim == 1:
        cbar.set_label('Infectious Population (%)')
        cbar.ax.set_yticklabels(map(lambda s: f'{round(s*100, 1)}', cticks))
        # plt.title(fr'$P_{{vac}}={p}\%$ - {vac_d[v]}')
        plt.ylabel(r'$P_{iso} (\%)$', fontsize=15)
        plt.tight_layout()
        plt.savefig(f'heatmaps/sim1/v{v}_v{p}.png')
    elif sim == 2:
        cbar.set_label('Infectious Population (%)')
        cbar.ax.set_yticklabels(map(lambda s: f'{round(s*100, 1)}', cticks))
        # plt.title(fr'$P_{{iso}}={p}\%$ - {vac_d[v]}')
        plt.ylabel(r'$P_{vac} (\%)$', fontsize=15)
        plt.tight_layout()
        plt.savefig(f'heatmaps/sim2/v{v}_i{p}.png')
    else:  # 0.1255808364
        cbar.set_label('Hospital Bed Occupancy (%)')
        if v == 6 and p == 100:
            cbar.ax.set_yticklabels(map(lambda s: f'{round(100 * s * 1e-5 / 0.001255808364, 1)}'
                                    if round(100 * s * 1e-5 / 0.001255808364, 1) < 99.7 else '100', cticks))
        else:
            cbar.ax.set_yticklabels(map(lambda s: f'{round(100 * s / 0.001255808364, 1)}'
                                    if round(100 * s / 0.001255808364, 1) < 99.7 else '100', cticks))
        # plt.title(fr'$P_{{vac}}={p}\%$ - {vac_d[v]}')
        plt.ylabel(r'$P_{iso} (\%)$', fontsize=15)
        plt.tight_layout()
        plt.savefig(f'heatmaps/sim3/Hv{v}_v{p}.png')
    # plt.show()


def main():
    # plot()  # normal_plot
    vac = 85
    params = {'mathtext.default': 'regular'}     
    font = {'family': 'courier new', 'size': 14.5}
    plt.rc('font', **font)
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
