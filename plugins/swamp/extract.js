function(page) {
    var regex = /<img[^>]+src="([^"]+)"[^>]+alt="Swamp\s+Cartoon\s+of\s+the\s+Day/;
    var match = regex.exec(page);
    return match[1];
}
