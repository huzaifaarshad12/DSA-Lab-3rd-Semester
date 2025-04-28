# -*- coding: utf-8 -*-
"""
Created on Sun Sep 22 18:01:49 2024

@author: huzai
"""

#task 4

import pandas as pd
import matplotlib.pyplot as plt


df_fitbit = pd.read_csv(r'D:\Documents\Semester3\DSA Lab\Lab3\hourlySteps_merged.csv')

df_fitbit['ActivityHour'] = pd.to_datetime(df_fitbit['ActivityHour'])


specific_date = pd.to_datetime('2016-04-12')

df_filtered = df_fitbit[df_fitbit['ActivityHour'].dt.date == specific_date.date()]

if not df_filtered.empty:
    plt.figure(figsize=(9, 4))
    df_filtered['Time'] = df_filtered['ActivityHour'].dt.strftime('%H:%M')  
    labels = df_filtered['Time'].tolist()
    sizes = df_filtered['StepTotal'].tolist()
    plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=75)
    plt.title('Hourly Steps ', fontsize=12)
    plt.axis('equal')  
    plt.show()