function(page) {
    var regex = /<img[^>]*src="([^"]*pigknit.files.wordpress.com[^"]*)"/g;
    var match1 = regex.exec(page);
    var match2 = regex.exec(page);
    return match2[1];
}
