function(page) {
    var regex = /<img[^>]* src="([^"]+\/wp-content\/uploads\/[^"]*Suporte[^"]+)"/;
    var match = regex.exec(page);
    return match[1];
}
