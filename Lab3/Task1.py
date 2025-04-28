# -*- coding: utf-8 -*-
"""
Created on Sun Sep 22 15:40:50 2024

@author: huzai
"""


import pandas as pd
import matplotlib.pyplot as plt

df_fitbit = pd.read_csv(r'D:\Documents\Semester3\DSA Lab\Lab3\dailySteps_merged.csv')

df_fitbit['Date'] = pd.to_datetime(df_fitbit['ActivityDay'])

plt.figure(figsize=(9, 4))
plt.plot(df_fitbit['Date'], df_fitbit['StepTotal'], marker='o', color='red')
plt.xlabel('Date', fontsize=8)
plt.ylabel('Total Steps', fontsize=7)
plt.title('Total Steps on a Daily Basis', fontsize=8)
plt.xticks(rotation=43)
plt.grid(True)
plt.tight_layout()
plt.show()




