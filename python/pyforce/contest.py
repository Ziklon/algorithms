import urllib2
import string
from bs4 import BeautifulSoup
url='http://codeforces.com/contest/281/problem/A'
usock = urllib2.urlopen(url)
data = usock.read()	
usock.close()

print data
