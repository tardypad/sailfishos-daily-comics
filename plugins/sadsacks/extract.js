function(page) {
    var regex = /<img[^>]*src="(images\/comic\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
