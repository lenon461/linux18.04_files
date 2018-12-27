var http = require('http');
var fs = require('fs');
var url = require('url');

var express = require('express');
var app = express();

app.get('/', function (request, response) {

    fs.readFile('./slot.html', function (error,data) {

        response.writeHead(200,{'content-type':'text/html'});

        response.end(data);

    });

});

// app.use(express.static('/produce48'));



app.get('/produce48', function (request, response) {

    fs.readFile('index.jpg', function (error, data) {

        response.writeHead(200, { 'content-type': 'text/html' });

        response.end(data);

    });

});

app.listen(8888);
