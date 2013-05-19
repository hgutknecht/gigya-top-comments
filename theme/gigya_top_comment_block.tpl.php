<div class="gigya-top-comments">
<?php
  // waiting on final design now
  print '<ul id="gigya_top_content">';
  $i = 0;
  $length = count($query_content);
  $queue = 'Popular';
  foreach ($query_content as $article) {
    $article_content = node_load($article['sid']);
    $item = addslashes(htmlspecialchars($article_content->path));
    switch ($article_content->type) {
      case 'article':
        $node_title = $article_content->title;
        $node_path = 'node/' . $article['sid'];
        break;

      case 'mls_blog':
        $article_author = node_load($article_content->field_blog_author[0]['nid']);
        $node_title = $article_content->title;
        $node_path = 'node/' . $article['sid'];
        break;

      case 'video':
        $node_title = $article_content->title;
        $node_path = 'node/' . $article['sid'];
        break;

      default:
        continue 2;
        break;
    }
    $event_tracking = 'onClick="_gaq.push([\'_trackEvent\',\''. $queue . '\',\'Position-' . $i . '\',\'' . $item . '\']);"';
    print '<li class="top_content_item">';
      print '<span class="comment_count" ' . $event_tracking . '>' . l($article['comment_count'], $node_path) . '</span>';
      print '<div class="meta"><span class="article_title" ' . $event_tracking . '>' . l($node_title, $node_path) . '</span>';
    if ($i == $length - 1) {
      print '</div></li>';
    }
    else {
      print '</div></li><hr class="popular_item_divider" />';
    }
    $i++;
  }
  print '</ul>';
?>
</div>