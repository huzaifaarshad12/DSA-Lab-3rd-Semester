# -*- coding: utf-8 -*-
"""
Created on Sun Sep 22 17:01:34 2024

@author: huzai
"""

import pandas as pd
import matplotlib.pyplot as plt

df_fitbit = pd.read_csv(r'D:\Documents\Semester3\DSA Lab\Lab3\sleepDay_merged.csv')

df_fitbit['Date'] = pd.to_datetime(df_fitbit['SleepDay'])


plt.figure(figsize=(9, 4)) 
plt.scatter(df_fitbit['Date'], df_fitbit['TotalTimeInBed'], color='blue')
plt.xlabel('Date', fontsize=12)
plt.ylabel('Total Time (m)', fontsize=10)  
plt.title('Total Time In Bed', fontsize=13)
plt.xticks(rotation=40)
plt.grid(True)
plt.tight_layout()
plt.show()