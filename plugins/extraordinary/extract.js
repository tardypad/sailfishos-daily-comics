function(page) {
    var regex = /<img[^>]*src="(.*\/comics\/comics\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
