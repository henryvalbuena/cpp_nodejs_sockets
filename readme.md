
# Purpose
(In Review - to expand) Desktop app to send/receive JSON data from the web, using an intermediary
web server for TCP socket communication.
First use, request and receive stock market information

# Technologies
Languages: C/C++, JavaScript, Node.js, Express.js

# To do list
SocketWrapper
- Send JSON format requests
- Receive JSON format responses
- Send HTTP requests
- Receive HTTP requests
- Windows portability (maybe)

ConsoleApp
- Display data received with a particular format
- Request for specific data

JSON Class
- Add error handling methods
- Review string, cstring copy performance
- Reverse engineer JSON obj

# Done list
- Connectivity between client-server using sockets
- Desktop console app to test Connectivity
- Basic string data transmission

# Issues
- Check connectivity against remote servers
    - Local server nodejs (same LAN)
    - Remote server nodejs (Internet)