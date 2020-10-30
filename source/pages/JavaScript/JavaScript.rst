============================
JavaScript
============================

.. contents:: Table of Contents
	:local:
	
Introduction
============================

History of the JavaScript language
-----------------------------------

Evolution toward a Global language
-----------------------------------

Popularity
NodeJs
Typescript
Frameworks

Programming in JS
============================

First Program : webpage
----------------------------

.. code-block:: html
    
    <!DOCTYPE html>
    <html>
        <head>
            <meta charset="UTF-8">
            <title>Space Invader</title>
            <link rel="stylesheet" type="text/css" href="style.css" />
        </head>
        <body>
        </body>
    </html>

    <script type="text/javascript">
        /*
            We must wait that the web page is fully loaded before beggining
            to access and edit it's components (We wait DOMContentLoaded)
        */
        document.addEventListener("DOMContentLoaded", function() {
            
            /* 
                We can read the elements in the page with selectors.
                We store it into a variable with: let v = ...  
            */
            let body = document.querySelector("body")
            
            /*
                You can use console.log(...) to display text or objects 
                in the web browser console (Ctrl + Shift + J for Chrome)
            */
            console.log("Document loaded")
        })
    </script>

    <style type="text/css">
        * {
            padding: 0px;
            margin: 0px;
        }
    </style>

Variables
----------------------------

JavaScript is Dynamically typed. There is 'types' but they are computed on the go, you cannot statically declare the type of a variable. 
That's one of the reasons why JS is not a fast language. TypeScript has been created to fix this by enabling the declaration of the type,
but it's a virtual fix because in the end it's also compiled in JS.

.. code-block:: js

    /* Declare with LET */
    let a = 'A' /* This is my default declaration for the variables */
    let b /* You can also declare a variable without assigning it a value */
    let c = 15 /* The variable type is automaticly computed... */
    c = 'test' /* ...but no problem for assigning it everithing, no parse needed*/

    /* 
        Let is a local definition, you can only access it in the current bloc.
        To create global variables, just declare them outside the main bloc. 
    */
    function() { 
        let d = 'my local variable' 
        console.log(d) /* 'my local variable' : we are inside the bloc */ 
    }
    console.log(d) /* undefined : we are outside the bloc were d is defined */

    /* Declare with VAR */
    
    /* 
        Var is the same as Let but it's permit to declare variables in the Global 
        condext: it attach the var to the 'window' object instead of the bloc
    */
    function() { 
        var e = 'my global variable' 
        console.log(e) /* 'my global variable' */ 
    }
    console.log(e) /* 'my global variable' */
    console.log(window.e) /* 'my global variable' */

    /* Declare with CONST */
    const NUMBER = 1 /* const must be defined when declarated and cannot be edited */

Console Log
----------------------------

Console log display the items passed by parameters

.. code-block::
    /* Text */
    console.log('test here') 

    /* Array */
    console.log([{ id: 0, name: 'A'}, { id: 1, name: 'B'}, { id: 2, name: 'C'}])
    (3) [{…}, {…}, {…}]
        > 0: {id: 0, name: "A"}
        > 1: {id: 1, name: "B"}
        > 2: {id: 2, name: "C"}
        length: 3
        > __proto__: Array(0)

    /* Text */
    console.log('Insert %s here','text')
    /*
        You can interpolate values with flags:
        %s (string)
        %d (decimal)
        %j (json)
        %O (object with depth of 4)
        %o (object with depth of 2)
    */
        
    console.error() /* For errors */
    console.dir() /* For directories */
    class Console /* Create a console object */

Tests
----------------------------

.. code-block:: js

    if (/* Condition */) {
        /* Code */
    } else if (/* Condition */) {
        /* Code */
    } else {
        /* Code */
    }

Loops
----------------------------

.. code-block:: js

    for (let i = 0; i < 10; i++) {
        /* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 */
    }

    do {
        /* Code */
    } while (/* Condition */)

    while (/* Condition */) {
        /* Code */
    }

    let items = ['A','B','C']

    for (let i in items) {
        console.log(i) /* 0, 1, 2 */
        items[i] /* A, B, C */
    }

    for (let i of items) {
        console.log(i) /* A, B, C */
    }

Functions
----------------------------

.. code-block:: js

    /* Parameters with default values become optionnal */
    function print(parameter = 0) {
        console.log(parameter)
        return true /* You can choose to return something or not */
    }

    print() /* 0 */
    print('test') /* 'test' */

    /* You can also declare functions like this */
    let func = () => 'test' /* this function just return 'test' */
    console.log(func()) /* 'test' */

    let func = (parameterA, parameterB ...) => {
        /* Code */
    }

Selectors
----------------------------

.. code-block:: js

    console.log(document) /* reference all the informations on the current page */
    
    /* Get elements with querySelector */
    let body = document.querySelector("body") /* We select the html element body */ 
    document.querySelector("#idObject") /* We cans select object like in css, with the id... */
    document.querySelector(".classObject") /* ... and the class, but it only return the first */
    document.querySelectorAll(".classObject") /* To get all items in an array, we use querySelectorAll */

    /* Get elements with getElementById */
    document.getElementById('idObject') /* We can get the first*/

    /* Get elements with getElementByClassName */
    document.getElementByClassName('classA classB ...') /* We get the array of all elements that have both classes */
    document.getElementByClassName('class')[0] /* ... to get the first element of the list */

Events
----------------------------

.. code-block:: js

    setTimeout(function() { /* Code */ }, 5000) /* After 5000ms */
    setInterval(function() { /* Code */ } 3000) /* Every 3000ms */

    element.addEventListener('click', function(event) { /* Code */ })

    function().then(function(data) { /* Code */ }).catch(function(error) { /* Code */ })

    async function asynchrone() { 
        let value = await function() { /* Code */ }
        return value
    }

    try { /* Code */ } catch (error) { /* Code */ }

Typescript
===========================

.. todo::

    Language

Ajax
============================

.. code-block:: 

    function Send(url, params, callback) {
        let xhr = new XMLHttpRequest();
        xhr.open("POST", url, true);
        xhr.responseType = "json";
        xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

        xhr.onreadystatechange = function () {
            if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
                callback(xhr.response);
            }
        }
        let s = "";
        for (let attr in params) s += attr + "=" + params[attr] + "&";
        xhr.send(s);
    }

    function Get(url) {
        return new Promise(function(resolve, reject) {
            let xhr = new XMLHttpRequest();
            xhr.open('GET', url);
            xhr.onload = function () {
                
                let data = JSON.parse(xhr.responseText);
                resolve(data)
                //console.log(data[0]);
            }
            xhr.onerror = reject;
            xhr.send();		
        });
    }


p5
============================

.. todo::

    p5

NodeJs
===========================

"NodeJs is an open source cross-plateform back-end JavaScript Environment that execute javaScript outside a web browser.
It was build in 2009 in JavaScript and in C/C++ where JavaScript was performing too slow.
Node use V8 to compile JS source code to native machine code at runtime.

Downlaod Node: https://nodejs.org/en/download/

.. code-block:: 

    node --version

    node
    > 2 + 2
    4
    > .help
    > .exit

    node file.js

Node Package Manager (npm)

.. code-block:: 

    npm install package
    npm view package
    npm search package
    npm help
    npm version
    npm list
    npm update /* update all packages */
    npm init /* Tool to initialize package.js */

    npm test
    npm start
    npm run serve



Node Path System (path)

.. code-block:: 

    const path = require('path')
    console.log('src' + path.sep + 'file')
    console.log(path.join('src','file'))

    path.basename(path) /* file name */
    path.dirname(path) /* folder name */
    path.extname(path) /* file extention */
    path.isAbsolute(path) /* false if relative */
    path.relative(pathA, pathB) /* return relative path to go from A to B */
    path.resolve('path',step,step,...) /* return the absolute path after completing the steps */


Node File System (fs)

.. code-block:: 

    const fs = require('fs')
    const path = require('path')
    const filename = path.join(__dirname, 'file") 
    /*
        __dirname: current repertory
        __filename: current file
    */

    fs.readFile(filename, (err, res) => {
        console.log(String(res))
    })

    fs.readDir(path, (err, res) => {
        console.log(res) /* files and subfolders */
    })

    fs.mkdir(path, (err) => {}) /* make folder */
    fs.copyFile(file, path, (err) => {}) /* copy file */
    fs.rename(file, new, (err) => {}) /* rename file/folder */
    fs.rmdir(path, (err) => {}) /* remove folder if empty */
    fs.unlink(path, new, (err) => {} /* remove file*/

Server HTTP (http)

.. code-block:: 

    const http = require('http')
    const server = http.createServer()
    server.listen(4000, 'localhost')

    server.on('request', (req, res) => {
        res.setHeader('Content-Type', 'text/html; charset=utf-8')

        res.write('Hello world')
        res.end()
    })

VueJs
===========================

Installation
---------------------------

Framework
---------------------------

Router
---------------------------

Vuetify
---------------------------

Vuex
---------------------------

Jest
---------------------------

.. code-block::

    npm install jest --save-dev

    package.json

    "scripts": {
        "test": "jest"
    },
    "jest": {
        "collectCoverage": true,
    }

    mkdir src/utils/__tests__
    cd src/utils/__tests__
    echo.>Element.spec.js

    /* Run tests */
    npm test --coverage 

.. code-block::

    src
    └───test
        ├───smoke
        └───unit
            ├───coverage
            └───specs // units tests here

.. code-block:: js

    import Element from 'src/element' /* With Babel*/
    const Element = required('src/element') /* Without Babel*/

    jest.mock('library') /* if the element use an external library */

    /* Describle contain one or more related tests */
    describle('description string', () => {

        /* Before each test */
        beforeEach(() => {
            /* Environment setup */
            process.env = {
                /* Environment variables setup */
            }       
        })

        /* After each test */
        afterEach(() => {
            /* Clean things */
        })

        /* You then describle your tests with: test or it (alias) */
        it('test description', () => {
            /* Variables Setup */
            const input = [
                { id:0, name:'A' }, 
                { id:0, name:'B' }, 
                { id:0, name:'C' } 
            ]
            const output = [{ id:0, name:'B' }]
            const spy = jest.spyOn(object, 'function')

            /* Function Test */
            // [...]

            /* Assertions */
            expect(/*...*/).toEquals(output) /* Result */
            expect(spy).toHaveBeenCalledTimes(1) /* Spy */
            expect(/*...*/).toMatch('Error") /* Errors */
        })
        
        it('async test description', async () => {
            /* Here we test with an async function */
        })


    }
    
            