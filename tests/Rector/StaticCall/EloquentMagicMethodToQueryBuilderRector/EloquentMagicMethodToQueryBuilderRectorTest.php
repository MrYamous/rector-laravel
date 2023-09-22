<?php

declare(strict_types=1);

namespace RectorLaravel\Tests\Rector\StaticCall\EloquentMagicMethodToQueryBuilderRector;

use Illuminate\Database\Eloquent\Model;
use Iterator;
use PHPUnit\Framework\Attributes\DataProvider;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;

final class User extends Model
{
    public static function staticMethodBelongsToModel(): void
    {
    }
}

final class EloquentMagicMethodToQueryBuilderRectorTest extends AbstractRectorTestCase
{
    #[DataProvider('provideData')]
    public function test(string $filePath): void
    {
        $this->doTestFile($filePath);
    }

    public static function provideData(): Iterator
    {
        return self::yieldFilesFromDirectory(__DIR__ . '/Fixture');
    }

    public function provideConfigFilePath(): string
    {
        return __DIR__ . '/config/configured_rule.php';
    }
}