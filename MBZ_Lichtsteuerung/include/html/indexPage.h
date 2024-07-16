const char indexPage[] = R"=====(
<html>

<head>
    <meta http-equiv="content-type" content="text/html;charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>MBZ Licht Steuerung</title>
</head>

<body>
    <div class="container">
        <h1>Main Page</h1>
        <p>
            <a class="btn btn-primary disabled" href="/" role="button">Home</a>
        </p>

        <form action="/Relay1" method="POST"><input type="submit" value="Toggle Relay 1"></form>
        <form action="/Relay2" method="POST"><input type="submit" value="Toggle Relay 2"></form>
        <form action="/Relay3" method="POST"><input type="submit" value="Toggle Relay 3"></form>
        <form action="/Relay4" method="POST"><input type="submit" value="Toggle Relay 4"></form>
        <form action="/Relay5" method="POST"><input type="submit" value="Toggle Relay 5"></form>
        <form action="/Relay6" method="POST"><input type="submit" value="Toggle Relay 6"></form>
        <form action="/Relay7" method="POST"><input type="submit" value="Toggle Relay 7"></form>
        <form action="/Relay8" method="POST"><input type="submit" value="Toggle Relay 8"></form>
        <form action="/Relay9" method="POST"><input type="submit" value="Toggle Relay 9"></form>
        <form action="/Relay10" method="POST"><input type="submit" value="Toggle Relay 10"></form>
        <form action="/Relay11" method="POST"><input type="submit" value="Toggle Relay 11"></form>
        <form action="/Relay12" method="POST"><input type="submit" value="Toggle Relay 12"></form>
        <form action="/Relay13" method="POST"><input type="submit" value="Toggle Relay 13"></form>
        <form action="/Relay14" method="POST"><input type="submit" value="Toggle Relay 14"></form>
        <form action="/Relay15" method="POST"><input type="submit" value="Toggle Relay 15"></form>
        <form action="/Relay16" method="POST"><input type="submit" value="Toggle Relay 16"></form>

        <p>Copyright (C) 2024 --- MBZ "Saxonia" Oberlungwitz e.V.</a>.</p>
    </div>
</body>

</html>
)=====";