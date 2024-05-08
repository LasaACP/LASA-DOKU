from flask import Flask, render_template, send_file
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('sudokuUI.html')

@app.route('/generate_sudoku')
def generate_sudoku():
    # Call your C++ program to generate the Sudoku puzzle and update the CSV file
    subprocess.run(['./sudokuAlgorithm.exe'], check=True)
    return "fesoigujew0roigjwe"

@app.route('/outfile.csv')
def get_csv():
    # Change the path to match the location of your CSV file
    return send_file('outfile.csv', as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
    