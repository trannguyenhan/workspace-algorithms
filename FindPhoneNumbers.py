from flask import Flask, render_template, request, redirect
from werkzeug.utils import secure_filename
import os

def findPhonesNumbers(arr):
    result = []
    

arr = ["100000007", "123456789", "100012345"]

file = open("file.txt", "w")
print(file.filename)