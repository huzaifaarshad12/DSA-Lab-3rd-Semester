# -*- coding: utf-8 -*-
"""
Created on Sun Sep 22 16:01:01 2024

@author: huzai
"""

import pandas as pd
import matplotlib.pyplot as plt

df_fitbit = pd.read_csv(r'D:\Documents\Semester3\DSA Lab\Lab3\dailyActivity_merged.csv')

df_fitbit['Date'] = pd.to_datetime(df_fitbit['ActivityDate'])


plt.figure(figsize=(9, 4)) 
plt.bar(df_fitbit['Date'], df_fitbit['TotalDistance'], color='red')
plt.xlabel('Date', fontsize=10)
plt.ylabel('Total Distance (km)', fontsize=12)  
plt.title('Total Distance on a Daily Basis', fontsize=14)
plt.xticks(rotation=43)
plt.grid(True)
plt.tight_layout()
plt.show()
