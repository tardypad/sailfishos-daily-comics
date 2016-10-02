function(page) {
    var regex = /<img[^>]*src="(.*\/strips[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
