function(page) {
    var regex = /<img SRC="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
