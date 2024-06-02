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

        <form action="/LED" method="POST"><input type="submit" value="Toggle LED"></form>

        <p>Copyright (C) 2024 --- MBZ "Saxonia" Oberlungwitz e.V.</a>.</p>
    </div>
</body>

</html>
)=====";