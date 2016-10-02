function(page) {
    var regex = /<img[^>]*src="(\/storage\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
