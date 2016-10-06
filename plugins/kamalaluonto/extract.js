function(page) {
    var regex = /data-original="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
