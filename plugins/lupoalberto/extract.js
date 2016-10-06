function(page) {
    var regex = /href="([^"]*\/tavola-settimana\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
