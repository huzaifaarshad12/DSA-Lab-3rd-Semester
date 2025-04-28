from selenium import webdriver
from bs4 import BeautifulSoup
import pandas as pd
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Fix the path to Chrome WebDriver
service = Service(executable_path='C:\\Users\\huzai\\Downloads\\Compressed\\chromedriver-win64\\chromedriver-win64\\chromedriver.exe')
driver = webdriver.Chrome(service=service)
prices = []    # List to store price of the product
ratings = []   # List to store rating of the product

# Navigate to Flipkart
driver.get('https://www.daraz.pk/catalog/?spm=a2a0e.tm80335159.search.d_go&q=watches')

# Extract page source and parse it using BeautifulSoup
content = driver.page_source
soup = BeautifulSoup(content, 'html.parser')

# Loop through each product entry and extract details
for a in soup.findAll('div', attrs={'class': 'ant-col ant-col-20 ant-col-push-4 Jv5R8 css-1bkhbmc app'}):  # Adjust the class according to Flipkart's structure  # Adjust class for product name
    price = a.find('span', attrs={'class': 'ooOxS'})  # Adjust class for product price
    rating = a.find('span', attrs={'class': 'IcOsH'})  # Adjust class for product rating
    print(price.text)
    print(rating.text)
    breakpoint()
    if  price and rating:  # Ensure the element exists
        prices.append(price.text)
        ratings.append(rating.text)

# Create a DataFrame with the extracted data
df = pd.DataFrame({'Price': prices, 'Rating': ratings})

# Save the data to a CSV file
df.to_csv('products.csv', index=False, encoding='utf-8')

# Close the driver
driver.quit()
