WiFiServer server(80);

void webServerProcess(){
  
  WiFiClient client = server.available();   // listen for incoming clients
 
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
 
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
//            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
//            // and a content-type so the client knows what's coming, then a blank line:
//            client.println("HTTP/1.1 200 OK");
//            client.println("Content-type:text/html");
//            client.println();
// 
//            // the content of the HTTP response follows the header:
//            client.print("<center><img src=\"https://bootstraplogos.com/wp-content/uploads/edd/2018/08/logo-4.png\" width=\"300\" height=\"300\"><br>");
// 
//            client.print("<h1>My Robot</h1>");
//            client.print("<h2>(not yours)</h2>");
//
//            client.print("<br><a href=\"/F\"><img src=\"https://cdn.clipart.email/1e704a34fc59ffe42201802b567df254_arrow-keys-transparent-png-clipart-free-download-ywd_980-980.png\" width=\"75\" height=\"75\"></a><br>");
//
//            client.print("<a href=\"/L\"><img src=\"https://www.pinclipart.com/picdir/middle/184-1840670_back-left-arrow-square-button-outline-comments-down.png\" width=\"80\" height=\"80\"></a>");
//
//            client.print("<a href=\"/S\"><img src=\"data:image/jpeg;base64,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\" width=\"75\" height=\"75\"></a>");
//
//            client.print("<a href=\"/R\"><img src=\"https://image.flaticon.com/icons/svg/54/54382.svg\" width=\"70\" height=\"70\"></a><br>");
//
//            client.print("<a href=\"/B\"><img src=\"https://www.pinclipart.com/picdir/middle/403-4034784_png-file-svg-down-arrow-key-png-clipart.png\" width=\"80\" height=\"80\"></a>");
//            
//            client.print("<br><h2>Internal temp: ");
//            client.print((temprature_sens_read() - 32) / 1.8);
//            client.print(" C</h2><br>");
//
//            client.print("<br><h2>Sensor Level: ");
////            client.print(sensor_level);
//            client.print("</h2>");
//            
//            client.println("</center>");
//
//            // The HTTP response ends with another blank line:
//            client.println();
//            // break out of the while loop:
//            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
 
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /F")) {
          goForward();
        }
        if (currentLine.endsWith("GET /S")) {
          stopIt();
        }
        if (currentLine.endsWith("GET /B")) {
          goBack();
        }
        if (currentLine.endsWith("GET /R")) {
          goRight();
        }
        if (currentLine.endsWith("GET /L")) {
          goLeft();
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
