function(page) {
    var regex = /<img src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
