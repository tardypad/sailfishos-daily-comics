function(page) {
    var regex = /href="(\/images\/djmediatools\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
