import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt


def plot():
    s = 0
    iso = 0
    state = ['Infectious', 'Hospitalized', 'Vaccinated']
    df = [pd.read_csv(f'newsim/i{str(iso)}/v{str(v)}/epiPrevBR.csv') for v in (0, 50, 75, 85, 95)]
    t = df[0]['Time'].to_numpy()
    inf = [d[state[s]].to_numpy() for d in df]
    labels = ['00', '50', '75', '85', '95']
    fig, ax = plt.subplots(1, 1, figsize=(8.8, 5.7))
    ax.grid()
    ax.set_xlim(0, 400)
    if s == 0:
        ax.set_ylim(0, .28)
        plt.yticks(np.arange(0, .28, .04))
    for i, x in enumerate(inf):
        ax.plot(t, x, label=labels[i])
    ax.legend()
    plt.show()

def iso_csv():
    df = [pd.read_csv(f'iso0days/results{iso}/epiPrevBR.csv') for iso in range(100, -1, -5)]
    inf = [d['Infectious'].to_numpy() for d in df]
    titles = [f'{i}%' for i in range(100, -1, -5)]
    inf = pd.DataFrame(inf, titles)
    sns.heatmap(inf)
    plt.title('$P_{vac}=0.85$')
    plt.xlabel('Time(days)')
    plt.ylabel('$P_{iso}$')
    plt.tight_layout()
    plt.show()


def main():
    # iso_csv()
    plot()  # testing
    

if __name__ == '__main__':
    main()
