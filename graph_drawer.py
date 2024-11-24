import pandas as pd
import matplotlib.pyplot as plt
file_path = 'random.csv'  # можно указать два других файла чтобы получить соответствующие файлы
df = pd.read_csv(file_path)
df.columns = df.columns.str.strip()
print(df.columns)
plt.figure(figsize=(10, 6))
plt.plot(df['Test No.'], df['Merge Sort (ms)'], label='Merge Sort', color='blue', marker='o')
plt.plot(df['Test No.'], df['Hybrid Merge Sort (ms)'], label='Hybrid Merge Sort', color='red', marker='x')
plt.title('Время работы алгоритмов сортировки')
plt.xlabel('Размер массива')
plt.ylabel('Время работы (мс)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
