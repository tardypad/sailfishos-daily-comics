function(page) {
    var regex = /<img[^>]*src="(.*\/webkuva\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
