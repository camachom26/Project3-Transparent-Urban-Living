import pandas as pd

#https://www.geeksforgeeks.org/reading-specific-columns-of-a-csv-file-using-pandas/
#inspo for reading different columns
file_path = "C://Users//chmer//Desktop//FoodAccessResearchAtlasData2019.csv"

df = pd.read_csv(file_path, skipinitialspace=True, usecols=['CensusTract', 'State','County','Pop2010','PovertyRate','MedianFamilyIncome','LA1and10'])
output_file_path = 'C://Users//chmer//Desktop//output.csv'  # Specify the desired output file path

df.to_csv(output_file_path, index=False)
