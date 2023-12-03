const bodyParser = require("body-parser");
const cors = require("cors");
const app = require('express')();

const http = require('http').createServer(app)

var corsOptions = {
  origin: "http://localhost:8082"
};

app.use(cors(corsOptions));

// parse requests of content-type - application/json
 app.use(bodyParser.json());

// parse requests of content-type - application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({ extended: true }));


// simple route
app.get('/', (req, res) => {
  res.json({ message: "Welcome." });
})
require("./app/routes/main.routes")(app);

// set port, listen for requests
const PORT = process.env.PORT || 8082;
app.listen(PORT, ["192.168.8.149", "localhost" ],() => {
  console.log(`Server is running on port ${PORT}.`);
});

var fs = require('fs');
array = fs.readFileSync('labels.txt').toString().split("\n");