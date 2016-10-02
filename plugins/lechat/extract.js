function(page) {
    var regex = /<img[^>]*src="(.*\/strip\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
