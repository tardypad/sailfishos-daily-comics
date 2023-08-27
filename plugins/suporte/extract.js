function(page) {
    var regex = /<img[^>]* src="([^"]*\/wp-content\/uploads\/[^"]*\/Suporte_[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
