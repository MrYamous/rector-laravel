<?php

namespace RectorLaravel\Tests\Rector\MethodCall\WhereToWhereLikeRector\Fixture\Default;

use Illuminate\Contracts\Database\Query\Builder;

class Fixture
{
    public function run(Builder $query, NonModel $nonQuery)
    {
        $query->where('name', 'like', 'Rector');
        $query->orWhere('name', 'like', 'Rector');
        $query->orwhere('name', 'LIKE', 'Rector');
        $query->where('name', 'not like', 'Rector');
        $query->orwhere('name', 'not like', 'Rector');
        $query->orwhere('name', like: 'not like', value: 'Rector');

        // Case Sensitivity
        $query->where('name', 'like binary', 'Rector');
        $query->where('name', 'not like binary', 'Rector');
        $query->where('name', like: 'like binary', value: 'Rector');

        // Invalid
        $nonQuery->where('name', 'like', 'Rector');
    }
}
?>
-----
<?php

namespace RectorLaravel\Tests\Rector\MethodCall\WhereToWhereLikeRector\Fixture\Default;

use Illuminate\Contracts\Database\Query\Builder;

class Fixture
{
    public function run(Builder $query, NonModel $nonQuery)
    {
        $query->whereLike('name', 'Rector');
        $query->orWhereLike('name', 'Rector');
        $query->orWhereLike('name', 'Rector');
        $query->whereNotLike('name', 'Rector');
        $query->orWhereNotLike('name', 'Rector');
        $query->orWhereNotLike('name', value: 'Rector');

        // Case Sensitivity
        $query->whereLike('name', 'Rector', true);
        $query->whereNotLike('name', 'Rector', true);
        $query->whereLike('name', value: 'Rector', caseSensitive: true);

        // Invalid
        $nonQuery->where('name', 'like', 'Rector');
    }
}
?>
