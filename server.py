from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('test.html')

@app.route('/upload', methods=['POST'])
def upload():
    file = request.files['file']
    if file:
        content = file.read().decode('utf-8')
        return render_template('test.html', content=content)
    return 'No file uploaded!'

if __name__ == '__main__':
    app.run(debug=True)
