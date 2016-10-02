function(page) {
    var regex = /<img[^>]*src="(.*content\.php[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
