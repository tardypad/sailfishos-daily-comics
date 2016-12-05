function(page) {
    var regex = /<img[^>]*data-src="([^"]*\/static\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
