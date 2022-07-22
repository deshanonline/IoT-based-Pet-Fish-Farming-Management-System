# Import libraries
import cv2
import sqlite3
import datetime
import csv
import os
import glob

conn = sqlite3.connect('fishpopulation.db')
c = conn.cursor()


def create_table():
    c.execute('CREATE TABLE IF NOT EXISTS FishPopulation (Date TIMESTAMP, Number REAL)')


currentDateTime = datetime.datetime.now()

folder_path = r'/var/www/html/uploads'
file_type = '/*jpg'
files = glob.glob(folder_path + file_type)
max_file = max(files, key=os.path.getctime)

image = cv2.imread(max_file)
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

blur = cv2.GaussianBlur(gray, (11, 11), 0)
canny = cv2.Canny(blur, 30, 150, 3)
dilated = cv2.dilate(canny, (1, 1), iterations=0)

(cnt, hierarchy) = cv2.findContours(
    dilated.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
cv2.drawContours(rgb, cnt, -1, (0, 255, 0), 2)

print("fish count in the image : ", len(cnt))


def data_entry():
    date = currentDateTime
    number = len(cnt)

    c.execute("INSERT INTO FishPopulation (Date, Number) VALUES(?, ?)", (date, number))
    conn.commit()


print("Data Insert successfully")

create_table()
data_entry()


#def read_from_db():
#    c.execute('SELECT * FROM FishPopulation')
#    data = c.fetchall()
#    print("Recorded Data - ")
#    for row in data:
#        print(row)


print("Exporting data into CSV............")

cursor = conn.cursor()
cursor.execute("select * from FishPopulation")
with open("data.csv", "w") as csv_file:
    csv_writer = csv.writer(csv_file, delimiter="\t")
    csv_writer.writerow(['Column 1', 'Column 2'])
    csv_writer.writerows(cursor)

dirpath = os.getcwd() + "/data.csv"
print("Data exported Successfully into {}".format(dirpath))

c.close()
conn.close()
