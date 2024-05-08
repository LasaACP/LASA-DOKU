from flask import Flask, render_template, send_file

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('test.html')

@app.route('/outfile.csv')
def get_csv():
    # Change the path to match the location of your CSV file
    return send_file('outfile.csv', as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
