var express = require('express')
var app = express()
var fs = require('fs');
var template = require('./lib/template.js');

//route, routing
//app.get('/', (req, res) => res.send('Hello World!'))
app.get('/', function(request, response) {
  fs.readFile('./html/produce48.html', function (error,data) {

      response.writeHead(200,{'content-type':'text/html'});

      response.end(data);

  });
});

app.get('/page', function(req, res) {
  return res.send('/page');
});

app.listen(3000, function() {
  console.log('Example app listening on port 3000!')
});
