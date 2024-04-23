import pandas as pd
import matplotlib.pyplot as plt

# File paths of the four CSV files
csv_files = ["C://Users//chmer//CLionProjects//DSAProject3//cmake-build-debug//high_poverty_low_access.csv",
             "C://Users//chmer//CLionProjects//DSAProject3//cmake-build-debug//high_poverty_no_low_access.csv",
             "C://Users//chmer//CLionProjects//DSAProject3//cmake-build-debug//low_poverty_low_access.csv",
             "C://Users//chmer//CLionProjects//DSAProject3//cmake-build-debug//low_poverty_no_low_access.csv"]

# Names for the CSV files to be used as x-axis labels
csv_labels = ["High Poverty\n Food Accessible", "High Poverty\n Food Desert", "Low Poverty\n Food Accessible", "Low Poverty\n Food Desert"]

row_counts = []

for file in csv_files:
    df = pd.read_csv(file)
    row_counts.append(len(df))

plt.figure(figsize=(8, 6))
plt.bar(csv_labels, row_counts, color='blue')
plt.xlabel('CSV Files')
plt.ylabel('Number of Rows')
plt.title('Number of Rows in Each CSV File')
plt.show()
