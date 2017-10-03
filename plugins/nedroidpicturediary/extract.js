function(page) {
    var regex = /<img[^>]*src="(.*\/comics\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
