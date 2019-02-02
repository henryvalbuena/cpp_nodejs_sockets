const HTTP_PORT     =   process.env.PORT || 8080;
const express       =   require('express');
const app           =   express();
const net           =   require('net');

app.get('/', (req, res) => {
    res.write("Server: Hello...");
    res.write(HTTP_PORT).end();
});

const server = net.createServer((socket) => {
  console.log("CONNECTION RECEIVED");
  socket.on('data', data => {
    parseBody(data).then(body => {
      console.log(body);
    }, err => {
      console.log(err);
    }).then(() => {
        console.log("SENDING RESPONSE...");
      socket.write("This is the Server response.");
    });
  }).on('end', () => {
    console.log("CONNECTION ENDED");
  }).on('error', err => {
      console.log(err);
  });
}).on('error', (err) => {
  // handle errors here
  throw err;
});

function parseBody(chunk) {
  let body = "";
  return new Promise((done, err) => {
    body += chunk;
    if (body) done(body);
    else err("No data");
  });
}

app.listen(HTTP_PORT, () => {
    console.log("HTTP Server listening on: " + HTTP_PORT);
});

server.listen(1337, () => {
  console.log("TCP Server listening on: ", server.address());
});