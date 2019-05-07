function(page) {
    var regex = /<img[^>]*src="([^"]*\/uploads\/[^"]*\/tirinha[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
