function(page) {
    var regex = /\/cartoon.+?<img\ssrc="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
