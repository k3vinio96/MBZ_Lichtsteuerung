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

        <p>Copyright (C) 2024 --- MBZ "Saxonia" Oberlungwitz e.V.</a>.</p>
    </div>
</body>

</html>
)=====";