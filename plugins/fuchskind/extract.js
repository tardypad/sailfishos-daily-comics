function(page) {
    var regex = /<img[^>]*src="(galerie\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
