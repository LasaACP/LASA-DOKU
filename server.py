from flask import Flask, render_template, send_file
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('sudokuUI.html')

@app.route('/generate_sudoku')
def generate_sudoku():
    # Call C++ .exe file to generate the Sudoku puzzle and update the CSV file
    subprocess.run(['./sudokuAlgorithm.exe'], check=True)
    return "fesoigujew0roigjwe"

@app.route('/outfile.csv')
def get_csv():
    #returns corresponding csv file to fetch request
    return send_file('outfile.csv', as_attachment=True)

@app.route('/solution.csv')
def get_solution():
    #returns corresponding csv file to fetch request
    return send_file('solution.csv', as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
    