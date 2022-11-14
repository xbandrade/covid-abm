import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt


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

def heatmap():
    vac = 85  # percentage vaccinated
    v = 6  # vaccine
    vac_d = {0: 'No Vaccination', 1: 'AstraZeneca', 2: 'CoronaVac', 4: 'Janssen', 6: 'Pfizer', 8: 'BR Vaccines'}
    s = 0  # state
    state = ['Infectious', 'Hospitalized', 'Vaccinated']
    irange = range(100, -1, -5)
    df = [pd.read_csv(f'newsim/v{str(v)}-{vac}/i{str(iso)}/epiPrev.csv') for iso in irange]
    inf = [d[state[s]].to_numpy() for d in df]
    titles = [f'{i}%' for i in range(100, -1, -5)]
    inf = pd.DataFrame(inf, titles)
    sns.heatmap(inf)
    plt.title(f'$P_{{vac}}=0.85$ - {vac_d[v]}')
    plt.xlabel('Time(days)')
    plt.ylabel('$P_{iso}$')
    plt.tight_layout()
    plt.show()


def main():
    # heatmap()
    plot()  # normal_plot
    

if __name__ == '__main__':
    main()
