import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt


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
    iso_csv()
    

if __name__ == '__main__':
    main()
