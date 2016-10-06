function(page) {
    var regex = /<img[^>]*src="(.*\/strippy\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
