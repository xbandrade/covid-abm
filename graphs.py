import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import warnings

params = {'mathtext.default': 'regular' }     
plt.rcParams["font.family"] = "courier new"     
plt.rcParams.update(params)
warnings.filterwarnings('ignore')


def plot():
    vac = 85  # percentage vaccinated
    v = 8  # vaccine
    s = 1  # state
    irange = range(0, 101, 5)
    state = ['Infectious', 'Hospitalized', 'Vaccinated']
    df = [pd.read_csv(f'newsim/v{str(v)}-{vac}/i{str(iso)}/epiPrev.csv') for iso in irange]
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

def heatmap(v, vac, s):
    fig, ax = plt.subplots(1, 1, figsize=(8.8, 5.7))
    vac_d = {0: 'No Vaccination', 1: 'AstraZeneca', 2: 'CoronaVac', 4: 'Janssen', 6: 'Pfizer', 8: 'Vaccines Used in Brazil'}
    state = ['Infectious', 'Hospitalized', 'Vaccinated']
    irange = range(100, -1, -5)
    df = [pd.read_csv(f'newsim/v{str(v)}-{vac}/i{str(iso)}/epiPrev.csv') for iso in irange]
    inf = [d[state[s]].to_numpy() for d in df]
    titles = [f'{i}' for i in range(100, -1, -5)]
    inf = pd.DataFrame(inf, titles)
    sns.heatmap(inf, cmap='flare_r')
    ax.set_xticks(np.arange(0, 401, 50))
    ax.set_xticklabels((c for c in np.arange(0, 401, 50)), rotation=0)
    cbar = ax.collections[0].colorbar
    cticks = [float(t.get_text().replace('−','-')) for t in cbar.ax.get_yticklabels()]
    cbar.ax.set_yticklabels(map(lambda s: f'{round(s*100, 1)}%', cticks))
    ax.set_xlabel('Time(days)')
    plt.title(f'$P_{{vac}}={vac}\%$ - {vac_d[v]}')
    plt.ylabel('$P_{iso} (\%)$')
    plt.tight_layout()
    plt.savefig(f'heatmaps/v{v}_{vac}_{state[s][:3].lower()}.png')
    # plt.show()


def main():
    # plot()  # normal_plot
    vac = 85
    state = 0
    for v in (0, 1, 2, 4, 6, 8):
        print(f'vac {v} - {vac}%... ', end='')
        heatmap(v, vac, state)
    print('\nDone!')
    

if __name__ == '__main__':
    main()
