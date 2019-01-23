function(page) {
    var regex = /<img[^>]*src="([^"]*\/wp-content\/uploads\/[^"]*)"/g;
    var match = regex.exec(page);
    var match2 = regex.exec(page);
    var match3 = regex.exec(page);
    var match4 = regex.exec(page);
    return match4[1];
}
